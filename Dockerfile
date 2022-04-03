# This Dockerfile creates a custom sonar image 
# that includes sonar cxx plugin. 
# Run the following command to build the reimage:
# docker build -t <image_name> .
# The image create has been running and updated. 
# Quality rules and quality gates have been defined.
# To save the image :
# docker commit <container_id> <name_new_image:version>
# For the created image (named sonar/cxx:v1), login is: admin, password is ad (or ab).
FROM sonarqube:latest
COPY sonar-cxx-plugin-2.1.0.160.jar /opt/sonarqube/extensions/plugins/